# $NetBSD: Makefile,v 1.19 2001/11/06 22:23:49 jlam Exp $
#

DISTNAME=	plptools-0.6
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/tarballs/

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	FTP-like and NFS-like access tools to talk to the PSION

USE_BUILDLINK_ONLY=	YES
USE_GNU_READLINE=	# uses rl_filename_quoting_desired flag

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}
LIBS+=			-ltermcap

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
