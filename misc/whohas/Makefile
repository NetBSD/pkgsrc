# $NetBSD: Makefile,v 1.6 2011/08/14 13:45:17 obache Exp $
#

DISTNAME=	whohas-0.22
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.philippwesche.org/200811/whohas/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.philippwesche.org/200811/whohas/intro.html
COMMENT=	Query several packaging systems for a program

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_LANGUAGES=	# none

REPLACE_PERL=	program/whohas

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/de/man1 \
			share/doc/whohas

do-build:
	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/program/whohas ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/share/man/man1/whohas.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/usr/share/man/de/man1/whohas.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/de/man1
	${INSTALL_DATA} ${WRKSRC}/intro* \
		${DESTDIR}${PREFIX}/share/doc/whohas

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
