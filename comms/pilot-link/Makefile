# $NetBSD: Makefile,v 1.25 2001/10/23 20:46:46 jlam Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-${PILOT_LINK_VERS}
COMMENT=		Tools to talk to the 3Com Pilot PDA

BUILDLINK_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_BUILDLINK_ONLY=	# defined
USE_PERL5=		# defined
USE_GNU_READLINE=	# defined

CONFIGURE_ARGS+=	--with-perl5=${PERL5}
CONFIGURE_ARGS+=	--with-readline21
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_DIR}

LIBS+=			-lpisock -liconv

INSTALL_TARGET=		install-execs install-man

.include "../../mk/x11.buildlink.mk"
.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
