# $NetBSD: Makefile,v 1.19 2022/06/28 11:31:13 wiz Exp $

DISTNAME=	smbchartool-2.3a
PKGREVISION=	13
CATEGORIES=	converters japanese
MASTER_SITES=	# ftp://ftp.samba.gr.jp/pub/samba-jp/tool/
DIST_SUBDIR=	smbchartool-2.3anb5

PATCH_SITES=		http://www.miraclelinux.com/technet/samba30/download/
PATCHFILES=		smbchartool-2.3a_3.0a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.miraclelinux.com/technet/samba30/migration.html
COMMENT=	File name conversion tool for Samba

DEPENDS+=	jcode-perl>=2.13:../../converters/jcode-perl
DEPENDS+=	p5-Text-Iconv>=1.4:../../converters/p5-Text-Iconv

USE_TOOLS+=	perl:run
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/smbchartool
REPLACE_PERL=	capecho hexecho smbfnconv

INSTALLATION_DIRS=	bin share/doc/smbchartool

do-install:
.for f in ${REPLACE_PERL}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/smbchartool
	${INSTALL_DATA} ${WRKSRC}/dot.bashrc.example \
		${DESTDIR}${PREFIX}/share/doc/smbchartool/dot.profile

.include "../../mk/bsd.pkg.mk"
