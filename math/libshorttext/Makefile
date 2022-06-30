# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:36 nia Exp $

DISTNAME=	libshorttext-1.1
PKGREVISION=	3
CATEGORIES=	math textproc
MASTER_SITES=	https://www.csie.ntu.edu.tw/~cjlin/libshorttext/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://www.csie.ntu.edu.tw/~cjlin/libshorttext/
COMMENT=	Library for short-text classification and analysis
LICENSE=	modified-bsd

DEPENDS+=	liblinear-[0-9]*:../../math/liblinear \
		libsvm-[0-9]*:../../math/libsvm

USE_LANGUAGES=	c c++

REPLACE_PYTHON=		*.py demo/*.py ${PYUTILS}
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
INSTALLATION_DIRS=	bin share/examples/libshorttext/demo \
	share/doc/libshorttext ${ADDITIONAL_FILES:H:S,^,${PYSITELIB}/,:O:u}

PYUTILS+= \
	libshorttext/classifier/classifier_impl.py \
	libshorttext/classifier/learner/learner_impl.py \
	libshorttext/analyzer/analyzer_impl.py \
	libshorttext/analyzer/selector.py \
	libshorttext/classifier/learner/liblinear/python/liblinear.py \
	libshorttext/classifier/learner/liblinear/python/liblinearutil.py \
	libshorttext/converter/converter_impl.py \
	libshorttext/converter/stemmer/porter.py \
	libshorttext/classifier/grid.py

ADDITIONAL_FILES+= \
	${PYUTILS} \
	libshorttext/analyzer/__init__.py \
	libshorttext/converter/stop-words/stoplist-nsp.regex.pickle \
	libshorttext/converter/stop-words/stoplist-nsp.regex \
	libshorttext/converter/stemmer/__init__.py \
	libshorttext/converter/stemmer/porter.so.1 \
	libshorttext/converter/__init__.py \
	libshorttext/__init__.py \
	libshorttext/classifier/__init__.py \
	libshorttext/classifier/learner/liblinear/train \
	libshorttext/classifier/learner/liblinear/predict \
	libshorttext/classifier/learner/liblinear/liblinear.so.1 \
	libshorttext/classifier/learner/__init__.py \
	libshorttext/classifier/learner/util.so.1

do-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_SCRIPT} text-predict.py text-train.py text2svm.py \
		${DESTDIR}${PREFIX}/bin; \
	${INSTALL_DATA} README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}; \
	${CP} -Rp demo ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
.for f in ${ADDITIONAL_FILES}
	${CP} -p ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PYSITELIB}/${f}
.endfor

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
