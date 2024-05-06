# $NetBSD: Makefile,v 1.15 2024/05/06 08:33:50 jperkin Exp $

DISTNAME=	ncurses-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ncurses-${VER}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/ncurses-ruby/
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-lgpl-v2.1 OR gnu-lgpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eclubb/ncurses-ruby
COMMENT=	Ruby interface to ncurses

VER=			1.2.4
USE_RUBY_EXTCONF=	YES

DOCS=			COPYING Changes MANIFEST README THANKS TODO VERSION
DOCDIR=			${RUBY_DOC}/ncurses
EGDIR=			${RUBY_EG}/ncurses
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}
REPLACE_RUBY_DIRS=	examples

PLIST_SUBST+=		DOCDIR=${DOCDIR} EGDIR=${EGDIR}

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/ruby/modules.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
