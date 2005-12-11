# $NetBSD: Makefile,v 1.3 2005/12/11 11:16:35 wulf Exp $

DISTNAME=	gnuradio-core-2.6
COMMENT=        Runtime system and DSP blocks for GNU Radio

PYTHON_PATCH_SCRIPTS+=		src/lib/filter/generate_all.py
PYTHON_PATCH_SCRIPTS+=		src/lib/general/generate_all.py
PYTHON_PATCH_SCRIPTS+=		src/lib/swig/gen-swig-bug-fix
PYTHON_PATCH_SCRIPTS+=		src/python/gnuradio/gruimpl/freqz.py
PYTHON_PATCH_SCRIPTS+=		src/python/gnuradio/blksimpl/gmsk.py
PYTHON_PATCH_SCRIPTS+=		src/python/gnuradio/blksimpl/gmsk2.py
PYTHON_PATCH_SCRIPTS+=		src/python/gnuradio/gruimpl/lmx2306.py
PYTHON_PATCH_SCRIPTS+=		src/python/gnuradio/gruimpl/gnuplot_freqz.py
PYTHON_PATCH_SCRIPTS+=		src/python/gnuradio/gr_unittest.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../devel/swig13/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
