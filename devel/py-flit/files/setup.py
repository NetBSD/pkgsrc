#!/usr/bin/env python

from setuptools import setup

packages = \
['flit', 'flit.vcs', 'flit.vendorized', 'flit.vendorized.readme']

package_data = \
{'': ['*'], 'flit': ['license_templates/*']}

install_requires = \
['flit_core >=3.6.0', 'requests', 'docutils', 'tomli', 'tomli-w']

extras_require = \
{'doc': ['sphinx', 'sphinxcontrib_github_alt', 'pygments-github-lexers'],
 'test': ['testpath', 'responses', 'pytest>=2.7.3', 'pytest-cov']}

entry_points = \
{'console_scripts': ['flit = flit:main']}

setup(name='flit',
      version='3.6.0',
      description='A simple packaging tool for simple packages.',
      author=None,
      author_email='Thomas Kluyver <thomas@kluyver.me.uk>',
      url=None,
      packages=packages,
      package_data=package_data,
      install_requires=install_requires,
      extras_require=extras_require,
      entry_points=entry_points,
      python_requires='>=3.6',
     )
