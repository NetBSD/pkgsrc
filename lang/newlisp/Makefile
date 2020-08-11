# $NetBSD: Makefile,v 1.15 2020/08/11 17:18:59 hauke Exp $
#

DISTNAME=	newlisp-10.7.5
PKGREVISION=	1
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
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-readline

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-configure
SUBST_MESSAGE.interpreter=	Fix shebang
SUBST_FILES.interpreter=	util/syntax.cgi util/newlispdoc
SUBST_SED.interpreter=		-e 's,/usr/bin/newlisp,${PREFIX}/bin/newlisp,'
SUBST_SED.interpreter+=		-e 's,/usr/local/bin/newlisp,${PREFIX}/bin/newlisp,'
SUBST_SED.interpreter+=		-e 's,/usr/bin/env newlisp,${PREFIX}/bin/newlisp,'

LDFLAGS+=	-lreadline

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
