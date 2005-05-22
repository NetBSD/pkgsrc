# $NetBSD: Makefile,v 1.29 2005/05/22 20:07:44 jlam Exp $
#

DISTNAME=	plptools-0.12
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=plptools/}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://plptools.sourceforge.net/
COMMENT=	FTP-like and NFS-like access tools to talk to the PSION

USE_GNU_READLINE=	# uses rl_filename_quoting_desired flag
USE_TOOLS+=		gmake
USE_LANUGAGES=		c c++
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}
LIBS+=			-ltermcap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
