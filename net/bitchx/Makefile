# $NetBSD: Makefile,v 1.1.1.1 2000/11/09 14:50:38 wiz Exp $

DISTNAME=	ircii-pana-1.0c17
PKGNAME=	bitchx-1.0.3.17
WRKSRC=		${WRKDIR}/BitchX
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitchx.org/pub/BitchX/source/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.bitchx.org/

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-termcap	# forcibly refuse to use ncurses

# We don't need the CVS files, and if we don't delete them, they get
# installed later on; ignore error code, since we delete the directories
# before find can descend into them.
post-extract:
	-${FIND} ${WRKDIR}/BitchX/bitchx-docs -type d -name CVS \
		-exec ${RM} -r {} \; 2> /dev/null

.include "../../mk/bsd.pkg.mk"
