# $NetBSD: Makefile,v 1.10 2006/10/14 08:06:07 wiz Exp $
#

DISTNAME=	elscreen-1.4.3
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/
DISTFILES=	${DISTNAME}.tar.gz \
		elscreen-dired-0.1.0.tar.gz \
		elscreen-dnd-0.0.0.tar.gz \
		elscreen-gf-1.5.1.tar.gz \
		elscreen-goby-0.0.0.tar.gz \
		elscreen-howm-0.1.0.tar.gz \
		elscreen-server-0.0.1.tar.gz \
		elscreen-w3m-0.2.2.tar.gz \
		elscreen-wl-0.7.0.tar.gz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.morishima.net/~naoto/software/elscreen/
COMMENT=	Window manager within Emacs

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel-[0-9]*:../../devel/apel
.endif

NO_BUILD=	yes

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/elscreen
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/elscreen
	@${INSTALL_DATA} ${WRKDIR}/*/*.el ${EMACS_LISPPREFIX}/elscreen
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/elscreen

.include "../../mk/bsd.pkg.mk"
