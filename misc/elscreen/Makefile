# $NetBSD: Makefile,v 1.20 2013/02/17 19:18:07 dholland Exp $
#

DISTNAME=	elscreen-1.4.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
#PKGREVISION=
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/ \
		ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/old/
DISTFILES=	${DISTNAME}.tar.gz \
		elscreen-color-theme-0.0.0.tar.gz \
		elscreen-dired-0.1.0.tar.gz \
		elscreen-dnd-0.0.0.tar.gz \
		elscreen-gf-1.5.3.tar.gz \
		elscreen-goby-0.0.0.tar.gz \
		elscreen-howm-0.1.3.tar.gz \
		elscreen-server-0.2.0.tar.gz \
		elscreen-w3m-0.2.2.tar.gz \
		elscreen-wl-0.8.0.tar.gz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.morishima.net/~naoto/software/elscreen/
COMMENT=	Window manager within Emacs
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c

NO_BUILD=	yes

EMACS_BUILDLINK=# empty

INSTALLATION_DIRS+= ${EMACS_LISPPREFIX}/elscreen
INSTALLATION_DIRS+= share/doc/elscreen

do-install:
	${INSTALL_DATA} ${WRKDIR}/*/*.el ${DESTDIR}${EMACS_LISPPREFIX}/elscreen
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/elscreen

.include "../../editors/emacs/modules.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
