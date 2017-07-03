from os import getcwd
from os.path import join
from distutils.dist import Distribution
from distutils.command.build import build
b = build(Distribution())
b.finalize_options()
print(join(getcwd(), b.build_platlib))
