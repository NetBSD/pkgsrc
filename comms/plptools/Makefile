# $NetBSD: Makefile,v 1.24 2004/04/25 00:36:04 wiz Exp $
#

DISTNAME=	plptools-0.6
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/tarballs/

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	FTP-like and NFS-like access tools to talk to the PSION

USE_BUILDLINK3=		YES
USE_GNU_READLINE=	# uses rl_filename_quoting_desired flag
USE_LANUGAGES=		c c++
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}
LIBS+=			-ltermcap

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
