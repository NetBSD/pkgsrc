# $NetBSD: Makefile,v 1.1.1.1 2000/03/04 00:21:43 pooka Exp $

DISTNAME=	mutt-1.1.7i
WRKSRC=		${WRKDIR}/mutt-1.1.7
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.mutt.org/pub/mutt/devel/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.gbnet.net/pub/mutt-international/devel/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/devel/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/devel/
DISTFILES=	mutt-1.1.7i.tar.gz charmaps-0.0.tar.gz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake

EXTRACT_ONLY=	mutt-1.1.7i.tar.gz

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+= --with-curses=${LOCALBASE} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt \
		 --enable-pop --enable-imap
LDFLAGS+=	-s

MIRROR_DISTFILE=no
RESTRICTED=	"Contains PGP code"

.include "../../mk/bsd.prefs.mk"

.if !(defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES)
IGNORE=		"Contains PGP code"
.endif

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	LOCALEBASE=lib
.else
PLIST_SUBST+=	LOCALEBASE=share
.endif

.if ${OPSYS} == "NetBSD"
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
.endif

post-extract:
	(cd ${WRKSRC} ; ${GTAR} -zxpf ${DISTDIR}/charmaps-0.0.tar.gz)

.include "../../mk/bsd.pkg.mk"
