# $NetBSD: Makefile,v 1.2 2001/09/28 02:15:02 wiz Exp $
#

DISTNAME=	sed-3.02
PKGNAME=	g${DISTNAME}
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU version of sed

BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake>=1.4:../../devel/automake

GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --program-prefix=g
INFO_FILES=	sed.info

pre-configure:
	cd ${WRKSRC} && \
	${LOCALBASE}/bin/aclocal && \
	${LOCALBASE}/bin/autoreconf && \
	${LOCALBASE}/bin/automake -i

.include "../../mk/bsd.pkg.mk"
