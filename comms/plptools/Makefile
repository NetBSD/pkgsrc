# $NetBSD: Makefile,v 1.23 2003/10/31 16:25:56 gavan Exp $
#

DISTNAME=	plptools-0.6
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/tarballs/

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	FTP-like and NFS-like access tools to talk to the PSION

USE_BUILDLINK2=		YES
USE_GNU_READLINE=	# uses rl_filename_quoting_desired flag
USE_GCC_SHLIB=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}
LIBS+=			-ltermcap

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
