# $NetBSD: Makefile,v 1.17 2001/06/12 20:33:01 jlam Exp $
#

DISTNAME=	plptools-0.6
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/tarballs/

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	FTP-like and NFS-like access tools to talk to the PSION

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GNU_READLINE=	# uses rl_filename_quoting_desired flag

.include "../../mk/bsd.prefs.mk"
.include "../../devel/readline/buildlink.mk"

CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}
LIBS+=			-ltermcap

.include "../../mk/bsd.pkg.mk"
