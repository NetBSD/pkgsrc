# $NetBSD: Makefile,v 1.8 2000/10/18 13:05:28 wiz Exp $

DISTNAME=	mutt-1.1.10i
WRKSRC=		${WRKDIR}/mutt-1.1.10
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.mutt.org/pub/mutt/devel/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.gbnet.net/pub/mutt-international/devel/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/devel/
DISTFILES=	mutt-1.1.10i.tar.gz charmaps-0.0.tar.gz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.mutt.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake

IGNORE=		"stable mutt available in mail/mutt is newer"

EXTRACT_ONLY=	mutt-1.1.10i.tar.gz

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+= --with-curses=${LOCALBASE} --with-exec-shell=/bin/ksh \
		 --with-docdir=${PREFIX}/share/doc/mutt \
		 --enable-pop --enable-imap
LDFLAGS+=	-s

.include "../../mk/bsd.prefs.mk"

.if !(defined(MUTT_INTERNATIONAL) && ${MUTT_INTERNATIONAL} == YES)
CRYPTO=		yes
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
