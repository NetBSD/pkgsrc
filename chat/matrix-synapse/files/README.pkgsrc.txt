To generate a Synapse configuration, run:

cd ${SYNAPSE_DATA} &&
${PYTHONBIN} -m synapse.app.homeserver \
	--server-name my.domain.name \
	--config-path ${PKG_SYSCONFDIR}/homeserver.yaml \
	--config-directory ${PKG_SYSCONFDIR} \
	--generate-config \
	--report-stats=no
