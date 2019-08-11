# $NetBSD: Makefile,v 1.87 2019/08/11 13:22:28 wiz Exp $

PKGREVISION= 2
.include "../../net/proftpd/Makefile.common"

COMMENT=	Highly configurable FTP server software

MODULES+=	\
		mod_ban \
		mod_copy \
		mod_ctrls_admin \
		mod_deflate \
		mod_dnsbl \
		mod_dynmasq \
		mod_exec \
		mod_ifsession \
		mod_ifversion \
		mod_load \
		mod_qos \
		mod_quotatab \
		mod_quotatab_file \
		mod_quotatab_radius \
		mod_quotatab_sql \
		mod_radius \
		mod_ratio \
		mod_readme \
		mod_rewrite \
		mod_sftp \
		mod_sftp_sql \
		mod_shaper \
		mod_site_misc \
		mod_sql \
		mod_sql_passwd \
		mod_tls \
		mod_tls_shmcache \
		mod_unique_id \
		mod_wrap2 \
		mod_wrap2_file \
		mod_wrap2_sql

CONFIGURE_ARGS+=	--with-shared=${MODULES:ts:}

RCD_SCRIPTS=		proftpd
REPLACE_PERL+=		contrib/ftpasswd
REPLACE_PERL+=		contrib/ftpmail
REPLACE_PERL+=		contrib/ftpquota
REPLACE_PERL+=		src/prxs.in

CONF_FILES=		${PREFIX}/share/examples/proftpd/basic.conf \
			${PKG_SYSCONFDIR}/proftpd.conf

INSTALLATION_DIRS+=	lib/proftpd
INSTALLATION_DIRS+=	share/doc/proftpd
INSTALLATION_DIRS+=	share/examples/proftpd

post-install:
.for i in NEWS README README.IPv6 README.LDAP README.PAM README.capabilities \
          README.classes README.controls README.facl README.modules
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/proftpd
.endfor
.for i in Configuration.html faq.html license.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/share/doc/proftpd
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample-configurations/*.conf \
		${DESTDIR}${PREFIX}/share/examples/proftpd
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/ftpasswd \
		${DESTDIR}${PREFIX}/share/examples/proftpd

.include "../../mk/bsd.pkg.mk"
