# $NetBSD: Makefile,v 1.1.1.1 2002/09/18 16:33:47 abs Exp $
#

DISTNAME=	mserv_irman-0.14
CATEGORIES=	audio
MASTER_SITES=	http://www.mono.org/abs/tools/mserv_irman/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.mono.org/abs/tools/mserv_irman/
COMMENT=	Control mserv mp3 jukebox program via infra-red remote

DEPENDS+=	mserv-[0-9]*:../../audio/mserv
DEPENDS+=	libirman>=0.4.1bnb3:../../sysutils/libirman
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
