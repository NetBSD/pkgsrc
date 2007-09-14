# $NetBSD: Makefile,v 1.4 2007/09/14 12:48:50 tnn Exp $
#

DISTNAME=	orpie-1.5.1
CATEGORIES=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/orpie/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.eecs.umich.edu/~pelzlpj/orpie/
COMMENT=	Curses-based reverse polish notation (RPN) calculator

PKG_DESTDIR_SUPPORT=	user-destdir
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
