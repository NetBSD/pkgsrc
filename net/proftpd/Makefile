# $NetBSD: Makefile,v 1.15 2004/10/13 23:03:52 xtraeme Exp $

DISTNAME=	proftpd-1.2.10
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		ftp://ftp.servus.at/ProFTPD/distrib/source/ \
		ftp://ftp.fsn.hu/pub/proftpd/distrib/source/ \
		ftp://ftp.middle-earth.it/proftpd/ \
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.proftpd.org/
COMMENT=	FTP server with Apache like configuration

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	# defined
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run
CONFIGURE_ARGS+=	--disable-sendfile
CONFIGURE_ARGS+=	--enable-ctrls

RCD_SCRIPTS=	proftpd

CONF_FILES=	${PREFIX}/share/examples/proftpd/basic.conf \
		${PKG_SYSCONFDIR}/proftpd.conf

PKG_SUPPORTED_OPTIONS = pam wrap quota
PKG_OPTIONS_VAR       = PROFTPD_OPTIONS

# This (or something like this must be in mk/bsd.options.mk) to allow 
# to see the supported options
##BUILD_DEFS+=PKG_SUPPORTED_OPTIONS

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--enable-auth-pam
.include "../../security/PAM/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwrap)
MODULES:=${MODULES}mod_wrap
.endif

MODULES=#defined
.if !empty(PKG_OPTIONS:Mquota)
MODULES:=${MODULES}mod_quota
.endif

## .if defined(PROFTPD_USE_LDAP) && ${PROFTPD_USE_LDAP} == "YES"
## MODULES:=	${MODULES}:mod_ldap
## DEPENDS+=	openldap-[0-9]*:../../databases/openldap
## .endif
##
## .if defined(PROFTPD_USE_MYSQL) && ${PROFTPD_USE_MYSQL} == "YES"
## MODULES:=	${MODULES}:mod_sql:mod_sql_mysql
## DEPENDS+=	mysql-client-[0-9]*:../../databases/mysql-client
## .endif
##
## .if defined(PROFTPD_USE_POSTGRES) && ${PROFTPD_USE_POSTGRES} == "YES"
## MODULES:=	${MODULES}:mod_sql:mod_sql_postgres
## DEPENDS+=	postgresql-client-[0-9]*:../../databases/postgresql-client
## .endif
##
## .if defined(PROFTPD_USE_README) && ${PROFTPD_USE_README} == "YES"
## MODULES:=	${MODULES}:mod_readme
## .endif

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-modules=${MODULES}
.endif

post-install:
	# documentation
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proftpd
.for i in NEWS README README.IPv6 README.LDAP README.PAM README.modules
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/proftpd
.endfor
.for i in Configuration.html faq.html license.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/proftpd
.endfor
	# examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/proftpd
	${INSTALL_DATA} ${WRKSRC}/sample-configurations/*.conf \
		${PREFIX}/share/examples/proftpd

.include "../../mk/bsd.pkg.mk"
