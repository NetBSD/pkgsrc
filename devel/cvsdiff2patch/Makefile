# $NetBSD: Makefile,v 1.3 2011/02/28 14:52:44 wiz Exp $
#

DISTNAME=	cvsdiff2patch-1.0.1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~alfred/sources/cvsdiff2patch/
COMMENT=	Convert CVS diffs into something that patch(1) understands

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	bin

do-extract:
	${RUN} ${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	${RUN} cd ${WRKSRC} && \
	${LIBTOOL} --mode=link ${CC} -o ${PKGBASE} ${PKGBASE}.c

do-install:
	${RUN} cd ${WRKSRC} && \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${PKGBASE} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
