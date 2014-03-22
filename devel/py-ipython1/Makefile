# $NetBSD: Makefile,v 1.3 2014/03/22 16:38:05 prlw1 Exp $

DISTNAME=	ipython-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lang
MASTER_SITES=	http://archive.ipython.org/release/1.2.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none
USE_TOOLS+=	gunzip

REPLACE_PYTHON+=	IPython/core/tests/test_inputtransformer.py
REPLACE_PYTHON+=	IPython/external/mathjax.py
REPLACE_PYTHON+=	IPython/kernel/zmq/ipkernel.py
REPLACE_PYTHON+=	IPython/lib/irunner.py
REPLACE_PYTHON+=	IPython/nbconvert/nbconvertapp.py
REPLACE_PYTHON+=	IPython/nbformat/v3/validator.py
REPLACE_PYTHON+=	IPython/parallel/apps/ipclusterapp.py
REPLACE_PYTHON+=	IPython/parallel/apps/ipcontrollerapp.py
REPLACE_PYTHON+=	IPython/parallel/apps/ipengineapp.py
REPLACE_PYTHON+=	IPython/parallel/apps/iploggerapp.py
REPLACE_PYTHON+=	IPython/parallel/controller/heartmonitor.py
REPLACE_PYTHON+=	IPython/parallel/scripts/ipcluster
REPLACE_PYTHON+=	IPython/parallel/scripts/ipcontroller
REPLACE_PYTHON+=	IPython/parallel/scripts/ipengine
REPLACE_PYTHON+=	IPython/parallel/scripts/iplogger
REPLACE_PYTHON+=	IPython/scripts/iptest
REPLACE_PYTHON+=	IPython/scripts/ipython
REPLACE_PYTHON+=	IPython/scripts/irunner
REPLACE_PYTHON+=	IPython/scripts/pycolor
REPLACE_PYTHON+=	IPython/terminal/ipapp.py
REPLACE_PYTHON+=	IPython/testing/mkdoctests.py
REPLACE_PYTHON+=	IPython/testing/plugin/iptest.py
REPLACE_PYTHON+=	IPython/testing/plugin/setup.py
REPLACE_PYTHON+=	IPython/utils/_process_posix.py
REPLACE_PYTHON+=	IPython/utils/pickleshare.py
REPLACE_PYTHON+=	docs/autogen_api.py
REPLACE_PYTHON+=	docs/do_sphinx.py
REPLACE_PYTHON+=	docs/gh-pages.py
REPLACE_PYTHON+=	examples/core/example-embed.py
REPLACE_PYTHON+=	examples/core/ipython-get-history.py
REPLACE_PYTHON+=	examples/lib/gui-glut.py
REPLACE_PYTHON+=	examples/lib/gui-gtk.py
REPLACE_PYTHON+=	examples/lib/gui-gtk3.py
REPLACE_PYTHON+=	examples/lib/gui-pyglet.py
REPLACE_PYTHON+=	examples/lib/gui-qt.py
REPLACE_PYTHON+=	examples/lib/gui-tk.py
REPLACE_PYTHON+=	examples/lib/gui-wx.py
REPLACE_PYTHON+=	examples/lib/ipkernel_qtapp.py
REPLACE_PYTHON+=	examples/lib/ipkernel_wxapp.py
# next two need to be quoted somehow
#REPLACE_PYTHON+=	examples/notebooks/Part 1 - Running Code.ipynb
#REPLACE_PYTHON+=	examples/notebooks/Part 3 - Plotting with Matplotlib.ipynb
REPLACE_PYTHON+=	examples/parallel/davinci/pwordfreq.py
REPLACE_PYTHON+=	examples/parallel/interengine/bintree_script.py
REPLACE_PYTHON+=	examples/parallel/task2.py
REPLACE_PYTHON+=	examples/parallel/task_profiler.py
REPLACE_PYTHON+=	examples/parallel/wave2D/RectPartitioner.py
REPLACE_PYTHON+=	examples/parallel/wave2D/communicator.py
REPLACE_PYTHON+=	examples/parallel/wave2D/parallelwave-mpi.py
REPLACE_PYTHON+=	examples/parallel/wave2D/parallelwave.py
REPLACE_PYTHON+=	examples/parallel/wave2D/wavesolver.py
REPLACE_PYTHON+=	examples/parallel/workflow/job_wrapper.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	setupegg.py

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/IPython/html/static/components/less.js/bin/lessc
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/IPython/html/static/components/marked/bin/marked

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
#.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
