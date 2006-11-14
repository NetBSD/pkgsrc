#!@PYTHON@
# EASY-INSTALL-ENTRY-SCRIPT: 'setuptools==@PKGVERSION@','console_scripts','easy_install'
__requires__ = 'setuptools==@PKGVERSION@'
import sys
from pkg_resources import load_entry_point

sys.exit(
   load_entry_point('setuptools==@PKGVERSION@', 'console_scripts', 'easy_install')()
)
