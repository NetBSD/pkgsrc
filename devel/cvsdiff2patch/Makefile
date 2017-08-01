# $NetBSD: Makefile,v 1.6 2017/08/01 14:58:55 wiz Exp $
#

DISTNAME=	cvsdiff2patch-1.0.1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.freebsd.org/~alfred/sources/cvsdiff2patch/
COMMENT=	Convert CVS diffs into something that patch(1) understands

USE_LIBTOOL=	yes

USE_FEATURES=	nbcompat # specifically fgetln

INSTALLATION_DIRS+=	bin

do-extract:
	${RUN} ${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	${RUN} cd ${WRKSRC} && \
	${LIBTOOL} --mode=link ${CC} ${CPPFLAGS} ${LDFLAGS} ${LIBS} -o ${PKGBASE} ${PKGBASE}.c

do-install:
	${RUN} cd ${WRKSRC} && \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${PKGBASE} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
