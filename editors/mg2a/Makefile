# $NetBSD: Makefile,v 1.15 2017/05/09 14:46:55 jperkin Exp $

DISTNAME=	mg2a
PKGNAME=	mg2a-1.11
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.wustl.edu/languages/c/unix-c/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Small, fast, public domain EMACS style editor

BUILD_TARGET=		mg
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONFLICTS+=  	mg-[0-9]*

pre-configure:
	set -e; cd ${WRKSRC}; \
	case ${OPSYS} in \
	SunOS) cp sys/sysv/Makefile . ;; \
	*) cp sys/bsd/Makefile . ;; \
	esac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${DESTDIR}${PREFIX}/bin/mg
	${INSTALL_MAN} ${FILESDIR}/mg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/mg.rc ${DESTDIR}${PREFIX}/bin/mg.rc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
