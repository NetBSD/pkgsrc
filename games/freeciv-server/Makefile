# $NetBSD: Makefile,v 1.34 2011/11/16 06:00:46 sbd Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
PKGREVISION=	2
COMMENT=	Freeciv game server

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

PKG_DESTDIR_SUPPORT=	user-destdir

#MAKE_JOBS_SAFE=		no

USE_GNU_READLINE=	yes
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--with-readline

# Uses rl_filename_completion_function() which was introduced in readline-4.2
BUILDLINK_API_DEPENDS.readline+=	readline>=4.2

SUBST_CLASSES+=			installfix
SUBST_STAGE.installfix=		post-patch
SUBST_FILES.installfix=		common/Makefile.in
SUBST_SED.installfix+=		-e 's|^install-exec-am: install-libLTLIBRARIES|install-exec-am: \# install-libLTLIBRARIES|'
SUBST_MESSAGE.installfix=	Suppressing installation of libs already in freeciv-share.

.include "../../games/freeciv-share/Makefile.common"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
