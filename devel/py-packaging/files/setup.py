#!/usr/bin/env python

from setuptools import setup

packages = \
['packaging']

package_data = \
{'': ['*']}

package_dir = \
{'': 'src'}

setup(name='packaging',
      version='23.0',
      description='Core utilities for Python packages',
      author=None,
      author_email='Donald Stufft <donald@stufft.io>',
      url=None,
      packages=packages,
      package_data=package_data,
      package_dir=package_dir,
      python_requires='>=3.7',
     )
