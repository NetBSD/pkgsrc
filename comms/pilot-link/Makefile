# $NetBSD: Makefile,v 1.29 2002/09/21 07:12:32 jlam Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-${PILOT_LINK_VERS}
PKGREVISION=		1
COMMENT=		Tools to talk to the 3Com Pilot PDA

BUILDLINK_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_GNU_READLINE=	# defined

CONFIGURE_ARGS+=	--with-perl5=${PERL5}
CONFIGURE_ARGS+=	--with-readline21
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

LIBS+=			-lpisock -liconv

INSTALL_TARGET=		install-execs install-man

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
