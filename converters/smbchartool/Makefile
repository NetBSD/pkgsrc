# $NetBSD: Makefile,v 1.1.1.1 2005/12/05 15:34:59 taca Exp $
#

DISTNAME=	smbchartool-2.3a
CATEGORIES=	converters japanese
MASTER_SITES=	ftp://ftp.samba.gr.jp/pub/samba-jp/tool/

PATCH_SITES=	http://www.miraclelinux.com/technet/samba30/download/
PATCHFILES=	smbchartool-2.3a_3.0a.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.miraclelinux.com/technet/samba30/migration.html
COMMENT=	File name conversion tool for Samba

DEPENDS+=	p5-jcode>=2.13:../../converters/p5-jcode
DEPENDS+=	p5-Text-Iconv>=1.4:../../converters/p5-Text-Iconv

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/smbchartool
REPLACE_PERL=	capecho hexecho smbfnconv

do-install:
.for f in ${REPLACE_PERL}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smbchartool
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/smbchartool
	${INSTALL_DATA} ${WRKSRC}/dot.bashrc.example \
		${PREFIX}/share/doc/smbchartool/dot.profile

.include "../../mk/bsd.pkg.mk"
