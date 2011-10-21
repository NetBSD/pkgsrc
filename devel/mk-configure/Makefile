# $NetBSD: Makefile,v 1.6 2011/10/21 23:30:31 cheusov Exp $
#

DISTNAME=	mk-configure-0.21.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/} \
		http://mova.org/~cheusov/pub/mk-configure/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# no languages

DOC_FILES=		README NEWS ChangeLog TODO FAQ COPYRIGHT \
			doc/presentation.pdf

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} BMAKE=${MAKE}

AUTO_MKDIRS=		yes

PKGDOCDIR=		share/doc/mk-configure
EGDIR=			share/examples/mk-configure

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PREFIX}/${PKGDOCDIR}
.endfor
	cp -Rp ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS && exists(/usr/xpg4/bin/awk)
REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	/usr/bin/awk
REPLACE.awk.new=	/usr/xpg4/bin/awk
REPLACE_FILES.awk=	mkc_check_version
.endif

.include "../../mk/bsd.pkg.mk"
