# $NetBSD: Makefile,v 1.6 2003/12/02 17:35:24 abs Exp $
#

DISTNAME=	mserv_irman-0.17
CATEGORIES=	audio
MASTER_SITES=	http://www.mono.org/abs/tools/mserv_irman/
EXTRACT_SUFX=   .tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/mserv_irman/
COMMENT=	Control mserv mp3 jukebox program via infra-red remote

DEPENDS+=	mserv-[0-9]*:../../audio/mserv
DEPENDS+=	libirman>=0.4.1.2nb3:../../sysutils/libirman
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Config-IniFiles-[0-9]*:../../devel/p5-Config-IniFiles

USE_PERL5=	YES

do-build:
	${SED} -e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'	\
		-e 's|/usr/local|${PREFIX}|g'			\
		< ${WRKSRC}/mserv_irman.pl			\
		> ${WRKSRC}/mserv_irman
	pod2man ${WRKSRC}/mserv_irman > ${WRKSRC}/mserv_irman.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mserv_irman ${PREFIX}/bin/mserv_irman
	${INSTALL_MAN} ${WRKSRC}/mserv_irman.1 ${PREFIX}/man/man1/mserv_irman.1

.include "../../mk/bsd.pkg.mk"
