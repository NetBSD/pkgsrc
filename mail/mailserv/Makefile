# $NetBSD: Makefile,v 1.1.1.1 2001/08/01 13:54:10 rh Exp $
#

DISTNAME=	mailserv
PKGNAME=	${DISTNAME}-3.27
NO_WRKSUBDIR=	YES
CATEGORIES=	mail
MASTER_SITES=	http://www.csicop.org/~fitz/www/mailserv/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.csicop.org/~fitz/www/mailserv/
COMMENT=	WWW interface to several types of mailing list servers

USE_PERL5=	YES
NO_BUILD=	YES

do-configure:
	cd ${WRKSRC} &&							\
	${CHMOD} 0755 mailserv &&					\
	${CP} mailserv mailserv.old &&					\
	${SED} < mailserv.old > mailserv				\
		-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|/usr/bin/perl|${PREFIX}/bin/perl|g"

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_SCRIPT} ${WRKSRC}/mailserv ${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_DATA_DIR} ${PREFIX}/etc/mailserv
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mailserv
.for cf in listproc listserv mail-list maiser majordomo-admin		\
	majordomo-share majordomo mlp pmdf smartlist subscribe
	[ -f ${PREFIX}/etc/mailserv/${cf}.cf ] ||			\
	${INSTALL_DATA} ${WRKSRC}/${cf}.cf ${PREFIX}/etc/mailserv
	${INSTALL_DATA} ${WRKSRC}/${cf}.cf ${PREFIX}/share/examples/mailserv
	cd ${PREFIX}/libexec/cgi-bin/mailserv &&			\
	${LN} -s mailserv ${cf}
.endfor

.include "../../mk/bsd.pkg.mk"
