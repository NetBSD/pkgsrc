# $NetBSD: Makefile,v 1.3 2001/09/09 20:36:34 agc Exp $
#

DISTNAME=	mailserv
PKGNAME=	${DISTNAME}-3.27
CATEGORIES=	mail
MASTER_SITES=	http://www.csicop.org/~fitz/www/mailserv/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.csicop.org/~fitz/www/mailserv/
COMMENT=	WWW interface to several types of mailing list servers

USE_PERL5=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}

do-configure:
.for file in mailserv cgi-lib.pl
	cd ${WRKSRC} &&							\
	${CHMOD} 0755 ${file} &&					\
	${CP} ${file} ${file}.old &&					\
	${SED} < ${file}.old > ${file}					\
		-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|/usr/local/bin/perl|${PREFIX}/bin/perl|g"		\
		-e "s|/usr/bin/perl|${PREFIX}/bin/perl|g"
.endfor

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_SCRIPT} ${WRKSRC}/mailserv ${PREFIX}/libexec/cgi-bin/mailserv
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-lib.pl ${PREFIX}/libexec/cgi-bin/mailserv
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mailserv
.for doc in ChangeLog LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/mailserv
.endfor

.include "../../mk/bsd.pkg.mk"
