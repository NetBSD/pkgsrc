# $NetBSD: Makefile,v 1.1.1.1 2001/03/23 22:11:24 zuntum Exp $
#

DISTNAME=	sms-1.8.8c
PKGNAME=	polsms-1.8.8c
CATEGORIES=	net
MASTER_SITES=	http://www.ceti.pl/~miki/komputery/download/sms/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.ceti.pl/~miki/komputery/sms.html
COMMENT=	useful command-line interface to sending SMS to Polish GSM networks

DEPENDS+=	gdbm-*:../../databases/gdbm

USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/sms

MAKE_ENV+=	CC="${CXX}" C="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sms ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/sms ${PREFIX}/bin/smsaddr
	${INSTALL_DATA_DIR} ${PREFIX}/share/sms ${PREFIX}/share/sms/doc	\
		${PREFIX}/share/sms/contrib
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/sms/doc
	cd ${WRKSRC}/doc && ${INSTALL_DATA} old_solaris NetBSD solaris 	\
		plusmail FreeBSD qmail eranet podziel_sms eragsm.asp	\
		${PREFIX}/share/sms/doc
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} mimecut procmailrc	\
		sms.cgi sms.html ${PREFIX}/share/sms/contrib

.include "../../mk/bsd.pkg.mk"
