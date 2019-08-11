# $NetBSD: Makefile,v 1.24 2019/08/11 13:21:29 wiz Exp $
#

DISTNAME=	mailserv
PKGNAME=	${DISTNAME}-3.29
PKGREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	http://www.barelyfitz.com/projects/mailserv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.barelyfitz.com/projects/mailserv/
COMMENT=	WWW interface to several types of mailing list servers

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

USE_TOOLS+=	perl:run
NO_BUILD=	YES

PKG_SYSCONFSUBDIR=	mailserv
EGDIR=		${PREFIX}/share/examples/mailserv
CONF_FILES=
.for cf in listproc listserv mail-list maiser majordomo-admin		\
	majordomo-share majordomo mlp pmdf smartlist subscribe
CONF_FILES+=	${EGDIR}/${cf}.cf ${PKG_SYSCONFDIR}/${cf}.cf
.endfor

INSTALLATION_DIRS=	libexec/cgi-bin

do-configure:
.for file in mailserv cgi-lib.pl
	cd ${WRKSRC} &&							\
	${CHMOD} 0755 ${file} &&					\
	${CP} ${file} ${file}.old &&					\
	${SED} < ${file}.old > ${file}					\
		-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"		\
		-e "s|/usr/local/bin/perl|${PREFIX}/bin/perl|g"		\
		-e "s|/usr/bin/perl|${PREFIX}/bin/perl|g"
.endfor

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_SCRIPT} ${WRKSRC}/mailserv ${DESTDIR}${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-lib.pl ${DESTDIR}${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
.for cf in listproc listserv mail-list maiser majordomo-admin		\
	majordomo-share majordomo mlp pmdf smartlist subscribe
	${INSTALL_DATA} ${WRKSRC}/${cf}.cf ${DESTDIR}${EGDIR}
	cd ${DESTDIR}${PREFIX}/libexec/cgi-bin/mailserv &&		\
	${LN} -s mailserv ${cf}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mailserv
.for doc in ChangeLog LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/mailserv
.endfor

.include "../../mk/bsd.pkg.mk"
