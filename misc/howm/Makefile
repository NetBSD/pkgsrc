# $NetBSD: Makefile,v 1.14 2020/01/26 17:31:43 rillig Exp $

DISTNAME=	howm-1.4.5
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://howm.osdn.jp/a/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://howm.osdn.jp/
COMMENT=	Write fragmentarily and read collectively
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-migemo-[0-9]*:../../textproc/migemo
DEPENDS+=	${EMACS_PKGNAME_PREFIX}migemo-elisp-[0-9]*:../../textproc/migemo-elisp

GNU_CONFIGURE=	yes

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-xemacs
CONFIGURE_ARGS+=	--with-packagedir=${EMACS_LISPPREFIX}
.else
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}
.endif

REPLACE_RUBY_DIRS=	ext
REPLACE_RUBY_PAT=	*.rb howm2 howmkara
.include "../../lang/ruby/replace.mk"

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
