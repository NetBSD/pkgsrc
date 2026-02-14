# $NetBSD: Makefile,v 1.21 2026/02/14 07:41:00 taca Exp $

DISTNAME=	howm-1.5.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kaorahi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kaorahi.github.io/howm/
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
