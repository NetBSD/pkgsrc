# $NetBSD: Makefile,v 1.21 2022/06/28 11:35:20 wiz Exp $
#

DISTNAME=	tacacs-F4.0.4.28
PKGNAME=	${DISTNAME:S,-F,-,}
PKGREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/tac_plus/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://www.shrubbery.net/tac_plus/
COMMENT=	Cisco AAA protocol (tacacs+) daemon (Shrubbery Networks version)
LICENSE=	cisco-license

CONFLICTS+=	tacacs-[0-9]*

USE_TOOLS+=	id # used in options.mk
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex perl
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_FEATURES+=	snprintf

CONFIGURE_ARGS+=	--with-acctfile=${VARBASE:Q}/log/tac_plus.acct
CONFIGURE_ARGS+=	--with-logfile=${VARBASE:Q}/log/tac_plus.log
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE:Q}/run/tac_plus.pid
CONFIGURE_ENV+=		PERLV_PATH=${PERL5:Q}
BUILD_DEFS+=		VARBASE

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=		-Duint16_t=u_int16_t -Duint32_t=u_int32_t
.endif

INSTALLATION_DIRS=	lib sbin ${PKGMANDIR}/man3 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 share/doc/tacacs

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${DESTDIR}${PREFIX}/sbin
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libtacacs.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/tac_pwd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tac_convert ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/tac_plus.8 ${WRKSRC}/tac_pwd.8 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${DESTDIR}${PREFIX}/share/doc/tacacs

.include "../../mk/bsd.pkg.mk"
