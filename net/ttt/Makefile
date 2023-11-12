# $NetBSD: Makefile,v 1.39 2023/11/12 13:23:14 wiz Exp $

DISTNAME=	ttt-1.8.2
PKGREVISION=	12
CATEGORIES=	net
#MASTER_SITES=	ftp://ftp.sonycsl.co.jp/pub/kjc/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.sonycsl.co.jp/person/kjc/software.html
COMMENT=	Tele Traffic Tapper

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=		install install-man
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			exec_prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

REPLACE_INTERPRETER+=		sys-BLTWISH
REPLACE.sys-BLTWISH.old=	.*bltwish
REPLACE.sys-BLTWISH.new=	${PREFIX}/bin/bltwish
REPLACE_FILES.sys-BLTWISH=	ttt.tcl

CFLAGS+=		-DUSE_INTERP_RESULT
CONFIGURE_ARGS+=	ttt_cv_prog_cflags=${CFLAGS:Q}

.include "options.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
