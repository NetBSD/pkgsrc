# $NetBSD: Makefile,v 1.1 2023/01/28 13:09:28 ryoon Exp $

.include "../../mail/notmuch/Makefile.common"
PKGNAME=		${DISTNAME:S/notmuch-/notmuch-emacs-/}

DEPENDS+=		emacs>=25.1:../../editors/emacs
DEPENDS+=		notmuch-[0-9]*:../../mail/notmuch

BUILDLINK_DEPMETHOD.desktop-file-utils=	build
.include "../../sysutils/desktop-file-utils/buildlink3.mk"

CONFIGURE_ARGS+=	--with-emacs

MAKE_FLAGS=		INFO_TEXI_FILES=doc/_build/texinfo/notmuch-emacs.texi
MAKE_FLAGS+=		COPY_INFO1= # empty
INSTALL_TARGET=		install-emacs install-info

.include "../../mk/bsd.pkg.mk"
