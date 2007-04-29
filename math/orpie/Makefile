# $NetBSD: Makefile,v 1.1.1.1 2007/04/29 20:01:45 tnn Exp $
#

DISTNAME=	orpie-1.4.3
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/orpie/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.eecs.umich.edu/~pelzlpj/orpie/
COMMENT=	Curses-based reverse polish notation (RPN) calculator

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-ncurses

INCOMPAT_CURSES+=	NetBSD-*-*
CONF_FILES+=		${PREFIX}/share/examples/orpie/orpierc \
			${PKG_SYSCONFDIR}/orpierc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
