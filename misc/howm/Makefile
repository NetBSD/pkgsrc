# $NetBSD: Makefile,v 1.5 2012/10/08 09:57:24 asau Exp $

DISTNAME=	howm-1.3.9.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://howm.sourceforge.jp/a/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://howm.sourceforge.jp/
COMMENT=	Write fragmentarily and read collectively
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-migemo-[0-9]*:../../textproc/migemo
DEPENDS+=	${EMACS_PKGNAME_PREFIX}migemo-elisp-[0-9]*:../../textproc/migemo-elisp

RUBY_VERSION_SUPPORTED= 193

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
