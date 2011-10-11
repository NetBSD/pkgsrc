# $NetBSD: Makefile,v 1.1.1.1 2011/10/11 13:03:18 ryoon Exp $
#

DISTNAME=	newlisp-10.3.3
CATEGORIES=	lang
MASTER_SITES=	http://www.newlisp.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.newlisp.org/
COMMENT=	Lisp-like, general-purpose scripting language
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure-alt
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-readline

USE_GNU_READLINE=	yes

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-configure
SUBST_MESSAGE.interpreter=	Fix shebang
SUBST_FILES.interpreter=	guiserver/*lsp util/syntax.cgi util/newlispdoc
SUBST_SED.interpreter=		-e 's,/usr/bin/newlisp,${PREFIX}/bin/newlisp,'
SUBST_SED.interpreter+=		-e 's,/usr/bin/env newlisp,${PREFIX}/bin/newlisp,'

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
