# $NetBSD: Makefile,v 1.28 2002/09/10 16:06:36 wiz Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-${PILOT_LINK_VERS}
PKGREVISION=		1
COMMENT=		Tools to talk to the 3Com Pilot PDA

BUILDLINK_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_BUILDLINK_ONLY=	# defined
USE_GNU_READLINE=	# defined

CONFIGURE_ARGS+=	--with-perl5=${PERL5}
CONFIGURE_ARGS+=	--with-readline21
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_DIR}

LIBS+=			-lpisock -liconv

INSTALL_TARGET=		install-execs install-man

.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
