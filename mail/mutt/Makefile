# $NetBSD: Makefile,v 1.33 1999/12/12 15:28:37 soren Exp $

DISTNAME=	mutt-${MUTT_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		ftp://ftp.uib.no/pub/mutt/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake
DEPENDS+=	libslang-*:../../devel/libslang

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+= --with-slang=${LOCALBASE} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt \
		 --enable-pop --enable-imap
LDFLAGS+=	-s

BUILD_DEFS+=	MUTT_INTERNATIONAL MUTT_VERSION

.include "../../mk/bsd.pkg.mk"

MUTT_BASE_VERSION=	1.0
.if defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES
MUTT_VERSION=		${MUTT_BASE_VERSION}i

MIRROR_DISTFILE=	no
RESTRICTED=		"Contains PGP code"
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$//}
.else
MUTT_VERSION=		${MUTT_BASE_VERSION}

WRKSRC=			${WRKDIR}/${DISTNAME}-us
.endif
