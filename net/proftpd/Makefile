# $NetBSD: Makefile,v 1.10 2003/09/23 18:26:05 kim Exp $

PKGNAME=	proftpd-1.2.8
DISTNAME=	proftpd-1.2.8p
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.proftpd.org/
COMMENT=	FTP server with Apache like configuration

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	# defined
USE_GMAKE=	# defined
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=--localstatedir=/var/run
CONFIGURE_ARGS+=--disable-sendfile

RCD_SCRIPTS=	proftpd

CONF_FILES=	${PREFIX}/share/examples/proftpd/basic.conf \
		${PKG_SYSCONFDIR}/proftpd.conf

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
## .if defined(PROFTPD_USE_QUOTA) && ${PROFTPD_USE_QUOTA} == "YES"
## MODULES:=	${MODULES}:mod_quota
## .endif
##
## .if defined(PROFTPD_USE_README) && ${PROFTPD_USE_README} == "YES"
## MODULES:=	${MODULES}:mod_readme
## .endif
##
## .if defined(PROFTPD_USE_WRAP) && ${PROFTPD_USE_WRAP} == "YES"
## MODULES:=	${MODULES}:mod_wrap
## .endif
##
## .if !empty(MODULES)
## CONFIGURE_ARGS+=--with-modules=${MODULES}
## .endif

post-install:
	# documentation
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proftpd
.for i in NEWS README README.LDAP README.PAM README.mod_sql README.modules
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
