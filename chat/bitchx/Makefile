# $NetBSD: Makefile,v 1.4 2001/02/16 13:51:21 wiz Exp $

DISTNAME=	ircii-pana-1.0c18
PKGNAME=	bitchx-1.0.3.18
WRKSRC=		${WRKDIR}/BitchX
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.bitchx.org/pub/BitchX/source/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

DEPENDS+=	ncurses>=5.2:../../devel/ncurses
# not enabled since BitchX dumps core on startup
#USE_CURSES=		yes
#REPLACE_NCURSES=	${WRKSRC}/bx-conf/ds_cell.c \
#			${WRKSRC}/bx-conf/ds_cell.h \
#			${WRKSRC}/bx-conf/file_cpy.c ${WRKSRC}/configure 

GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--with-tgetent	# forcibly refuse to use ncurses

# We don't need the CVS files, and if we don't delete them, they get
# installed later on; ignore error code, since we delete the directories
# before find can descend into them.
post-extract:
	-${FIND} ${WRKDIR}/BitchX/bitchx-docs -type d -name CVS \
		-exec ${RM} -r {} \; 2> /dev/null

# The WANT_NOTIFY_BITCHX_COM message after configure is misleading, we
# disable this by default.
post-configure:
	@${ECHO}
	@${ECHO} ===== WANT_NOTIFY_BITCHX_COM is disabled by default =====
	@${ECHO}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/BitchX.1 ${PREFIX}/man/man1
	# delete installed bzip2'd man page
	${RM} ${PREFIX}/man/man1/BitchX.1.bz2
	${INSTALL_DATA} ${WRKSRC}/doc/BitchX.doc ${PREFIX}/share/bx

.include "../../mk/bsd.pkg.mk"
