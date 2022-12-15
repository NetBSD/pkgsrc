# $NetBSD: Makefile,v 1.46 2022/12/15 12:14:17 jperkin Exp $

DISTNAME=		sam
PKGNAME=		sam-4.3
PKGREVISION=		4
CATEGORIES=		editors plan9
MASTER_SITES=		# ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=		.msg.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Unix version of Rob Pike's editor for plan9

DEPENDS+=		libXgFonts>=1.0nb1:../../fonts/Xg

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${GZCAT} $$extract_file | ${SH}

MANCOMPRESSED=		yes

INSTALLATION_DIRS=	bin include lib/X11/app-defaults \
	${PKGMANDIR}/man1 ${PKGMANDIR}/man3 ${PKGMANDIR}/man4 ${PKGMANDIR}/man6

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}		\
			MAN=${PKGMANDIR}

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
