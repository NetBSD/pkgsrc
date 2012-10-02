# $NetBSD: Makefile,v 1.3 2012/10/02 20:11:46 asau Exp $
#

DISTNAME=	newlisp-10.4.0
CATEGORIES=	lang
MASTER_SITES=	http://www.newlisp.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.newlisp.org/
COMMENT=	Lisp-like, general-purpose scripting language
LICENSE=	gnu-gpl-v3

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
