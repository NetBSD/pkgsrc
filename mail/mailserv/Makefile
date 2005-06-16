# $NetBSD: Makefile,v 1.10 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	mailserv
PKGNAME=	${DISTNAME}-3.29
CATEGORIES=	mail
MASTER_SITES=	http://www.csicop.org/~fitz/www/mailserv/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.csicop.org/~fitz/www/mailserv/
COMMENT=	WWW interface to several types of mailing list servers

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

USE_PERL5=	YES
USE_PKGINSTALL=	YES
NO_BUILD=	YES

PKG_SYSCONFSUBDIR=	mailserv
EGDIR=		${PREFIX}/share/examples/mailserv
CONF_FILES=
.for cf in listproc listserv mail-list maiser majordomo-admin		\
	majordomo-share majordomo mlp pmdf smartlist subscribe
CONF_FILES+=	${EGDIR}/${cf}.cf ${PKG_SYSCONFDIR}/${cf}.cf
.endfor
.undef cf

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
.undef file

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_SCRIPT} ${WRKSRC}/mailserv ${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-lib.pl ${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_DATA_DIR} ${EGDIR}
.for cf in listproc listserv mail-list maiser majordomo-admin		\
	majordomo-share majordomo mlp pmdf smartlist subscribe
	${INSTALL_DATA} ${WRKSRC}/${cf}.cf ${EGDIR}
	cd ${PREFIX}/libexec/cgi-bin/mailserv &&			\
	${LN} -s mailserv ${cf}
.endfor
.undef cf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mailserv
.for doc in ChangeLog LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/mailserv
.endfor
.undef doc

.include "../../mk/bsd.pkg.mk"
