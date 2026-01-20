#!@RCD_SCRIPTS_SHELL@

# PROVIDE: quasselcore
# REQUIRE: LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

# User-settable rc.conf variables and their default values:
: ${quasselcore_data:="@VARBASE@/db/quasselcore"}
: ${quasselcore_log:="@VARBASE@/log/quasselcore.log"}
: ${quasselcore_listen:="0.0.0.0,::"}
: ${quasselcore_args:="--configdir=${quasselcore_data} --logfile=${quasselcore_log} --listen=${quasselcore_listen}"}
: ${quasselcore_user:="@QUASSELCORE_USER@"}
: ${quasselcore_group:="@QUASSELCORE_GROUP@"}

name="quasselcore"
rcvar="${name}"
pidfile="@VARBASE@/run/${name}/${name}.pid"
command="@PREFIX@/sbin/daemonize"
procname="@PREFIX@/bin/${name}"
command_args="${command_args} -p ${pidfile}"
command_args="${command_args} ${procname} ${quasselcore_args}"
start_precmd="${name}_prestart"
keygen_cmd="${name}_keygen"
extra_commands="keygen"

quasselcore_keygen()
{
	cat > /tmp/.mkcert.cfg <<EOT
[req]
distinguished_name		= req_distinguished_name
prompt				= no
[req_distinguished_name]
countryName			= VA
stateOrProvinceName		= Valinor
localityName			= Valimar
organizationName		= Valimar Industry Ltd
EOT
	openssl req -config /tmp/.mkcert.cfg \
		-x509 -nodes -days 365 -newkey rsa:4096 \
		-keyout "${quasselcore_data}/quasselCert.pem" \
		-out "${quasselcore_data}/quasselCert.pem"
	chown ${quasselcore_user}:${quasselcore_group} "${quasselcore_data}/quasselCert.pem"
	chmod 400 "${quasselcore_data}/quasselCert.pem"
	rm -f /tmp/.mkcert.cfg
}

uasselcore_prestart()
{
	install -d -o ${quasselcore_user} -g ${quasselcore_group} ${quasselcore_data}
	install -d -o ${quasselcore_user} -g ${quasselcore_group} @VARBASE@/run/${name}

	if [ ! -f "${quasselcore_log}" ]; then
		install -o ${quasselcore_user} -g ${quasselcore_group} /dev/null ${quasselcore_log}
	fi
	if [ ! -f "${quasselcore_data}/quasselCert.pem" ]; then
		quasselcore_keygen
	fi
}

load_rc_config ${name}
run_rc_command "$1"
