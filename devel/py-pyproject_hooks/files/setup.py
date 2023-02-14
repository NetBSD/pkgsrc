#!/usr/bin/env python

from setuptools import setup

packages = \
['pyproject_hooks', 'pyproject_hooks._in_process']

package_data = \
{'': ['*']}

package_dir = \
{'': 'src'}

extras_require = \
{":python_version<'3.11'": ['tomli >=1.1.0 ']}

setup(name='pyproject_hooks',
      version='1.0.0',
      description='Wrappers to call pyproject.toml-based build backend hooks.',
      author=None,
      author_email='Thomas Kluyver <thomas@kluyver.me.uk>',
      url=None,
      packages=packages,
      package_data=package_data,
      package_dir=package_dir,
      extras_require=extras_require,
      python_requires='>=3.7',
     )
