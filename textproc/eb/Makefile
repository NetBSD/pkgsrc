# $NetBSD: Makefile,v 1.8 2002/06/12 01:14:49 uebayasi Exp $
# FreeBSD Id: ports/japanese/eb/Makefile,v 1.21 2000/08/21 03:39:42 kevlo Exp

DISTNAME=	eb-3.2.2
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/appendix/ \
		ftp://ftp.sra.co.jp/pub/misc/eb/
DISTFILES=	${EB_DISTFILES} \
		${EB_LISTS} \
		${EB_APPENDICES}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/eb/
COMMENT=	C library for accessing EB, EBG, EBXA and EPWING CD-ROM dictionaries

EB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EB_LISTS=	LIST \
		LIST-ja
EB_APPENDICES=	\
		cencro-1.0.tar.gz \
		chujiten-2.3.tar.gz \
		chujiten2-2.0.tar.gz \
		chujiten6-2.3.tar.gz \
		colloc-2.0.tar.gz \
		crownfj-2.0.tar.gz \
		crownfj2-1.0.tar.gz \
		crowngj-1.0.tar.gz \
		daihyakka-1.0.tar.gz \
		daijirin-2.0.tar.gz \
		dd75-2.0.tar.gz \
		genius-1.0.tar.gz \
		global-2.0.tar.gz \
		heritage-2.2.tar.gz \
		izumi-2.0.tar.gz \
		jitenban-2.4.tar.gz \
		jitenban97-2.1.tar.gz \
		kanjigen-2.0.tar.gz \
		kanjigen2-2.0.tar.gz \
		kojien-2.3.tar.gz \
		kojien2-2.0.tar.gz \
		kojien4-2.2.tar.gz \
		oxford-2.0.tar.gz \
		plus-2.0.tar.gz \
		readers-2.2.tar.gz \
		readers2-2.0.tar.gz \
		superdic98-1.0.tar.gz
EXTRACT_ONLY=	${EB_DISTFILES}

DIST_SUBDIR=		eb
USE_BUILDLINK_ONLY=	# Defined
USE_LIBTOOL=		# Defined
GNU_CONFIGURE=		# Defined
CONFIGURE_ARGS+=	--with-zlib
USE_GMAKE=		# Defined
TEXINFO_OVERRIDE=	YES
# For patterns like '... (install-info ...) ...'
TEXINFO_SUBST_SED+=	-e "s!^\(	.*\)\([ 	'(]\)install-info\([ 	]\)!\1\2${INSTALL_INFO}\3!g"

EB_APPENDIXDIR=	${PREFIX}/share/eb/appendix

post-extract:
	cd ${WRKSRC} && ${RM} -rf zlib

post-install:
	for f in ${EB_LISTS}; do \
		${INSTALL_DATA} ${_DISTDIR}/$${f} ${EB_APPENDIXDIR}; \
	done
	for f in ${EB_APPENDICES}; do \
		${GTAR} -C ${EB_APPENDIXDIR} -zxmf ${_DISTDIR}/$${f}; \
	done

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
