# $NetBSD: Makefile,v 1.12 2001/05/22 17:04:45 jlam Exp $
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
.include "../../devel/readline/Makefile.readline"

CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		LIBS="${LIBS}"

CPPFLAGS+=		-I${WRKINCDIR}
LIBS+=			-ltermcap

pre-configure: link-readline-headers link-readline-libs

.include "../../mk/bsd.pkg.mk"
