# $NetBSD: Makefile,v 1.23 2017/01/19 18:52:18 agc Exp $
#

DISTNAME=	elscreen-1.4.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/
MASTER_SITES+=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/old/
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

# Emacs 24 or later is not supported. Try wip/elscreen-current
# instead.
EMACS_VERSIONS_ACCEPTED= \
	emacs23 emacs23nox \
	emacs22 emacs22nox \
	emacs21 emacs21nox \
	emacs20

INSTALLATION_DIRS+= ${EMACS_LISPPREFIX}/elscreen
INSTALLATION_DIRS+= share/doc/elscreen

do-install:
	${INSTALL_DATA} ${WRKDIR}/*/*.el ${DESTDIR}${EMACS_LISPPREFIX}/elscreen
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/elscreen

.include "../../editors/emacs/modules.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
